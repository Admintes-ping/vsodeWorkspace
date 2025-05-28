#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RESOURCE_TYPES 2
#define MAX_PROCESSES 10
#define MAX_CMD_LENGTH 128

typedef enum
{
    READY,
    BLOCKED,
    RUNNING
} ProcessState;

// 进程控制块（PCB）
typedef struct PCB
{
    int pid;
    ProcessState state;
    int resources_held[MAX_RESOURCE_TYPES];
    struct PCB *next;
} PCB;

// 资源等待队列节点
typedef struct WaitNode
{
    PCB *proc;
    int amount;
    struct WaitNode *next;
} WaitNode;

// 资源控制块（RCB）
typedef struct RCB
{
    int rid;
    int available;
    int total;
    WaitNode *waiting_queue;
} RCB;

// 全局变量
PCB *ready_queue = NULL;
PCB *running_process = NULL;
RCB resources[MAX_RESOURCE_TYPES];
PCB processes[MAX_PROCESSES];
int next_pid = 0;

// 函数声明
void init_system();
void schedule();
int create_process();
void terminate_process(int pid);
int request_resource(int pid, int rid, int amount);
int release_resource(int pid, int rid, int amount);
void print_status();
void shell();

// 初始化系统
void init_system()
{
    // 初始化资源
    for (int i = 0; i < MAX_RESOURCE_TYPES; i++)
    {
        resources[i].rid = i;
        resources[i].total = 10;
        resources[i].available = 10;
        resources[i].waiting_queue = NULL;
    }

    // 初始化进程表
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        processes[i].pid = -1;
        processes[i].state = READY;
        memset(processes[i].resources_held, 0, sizeof(int) * MAX_RESOURCE_TYPES);
        processes[i].next = NULL;
    }

    // 创建初始进程
    create_process(); // init进程
}

// 创建新进程
int create_process()
{
    // 寻找空闲PCB
    int i;
    for (i = 0; i < MAX_PROCESSES; i++)
    {
        if (processes[i].pid == -1)
            break;
    }
    if (i >= MAX_PROCESSES)
        return -1;

    // 初始化PCB
    processes[i].pid = next_pid++;
    processes[i].state = READY;
    memset(processes[i].resources_held, 0, sizeof(int) * MAX_RESOURCE_TYPES);

    // 加入就绪队列
    PCB *new_proc = &processes[i];
    new_proc->next = NULL;

    if (ready_queue == NULL)
    {
        ready_queue = new_proc;
    }
    else
    {
        PCB *current = ready_queue;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_proc;
    }

    schedule();
    return new_proc->pid;
}

// 终止进程
void terminate_process(int pid)
{
    PCB *proc = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        if (processes[i].pid == pid)
        {
            proc = &processes[i];
            break;
        }
    }
    if (!proc)
        return;

    // 释放所有持有的资源
    for (int rid = 0; rid < MAX_RESOURCE_TYPES; rid++)
    {
        if (proc->resources_held[rid] > 0)
        {
            release_resource(pid, rid, proc->resources_held[rid]);
        }
    }

    // 从队列中移除
    if (running_process == proc)
    {
        running_process = NULL;
    }
    else
    {
        PCB *prev = NULL;
        PCB *current = ready_queue;
        while (current && current != proc)
        {
            prev = current;
            current = current->next;
        }
        if (current == proc)
        {
            if (prev)
            {
                prev->next = current->next;
            }
            else
            {
                ready_queue = current->next;
            }
        }
    }

    // 重置PCB
    proc->pid = -1;
    proc->state = READY;
    proc->next = NULL;

    schedule();
}

// 调度程序（简单轮转）
void schedule()
{
    if (running_process)
    {
        running_process->state = READY;
        running_process = NULL;
    }

    if (ready_queue)
    {
        running_process = ready_queue;
        running_process->state = RUNNING;
        ready_queue = ready_queue->next;
        running_process->next = NULL;

        // 将进程移到队列尾部
        if (ready_queue)
        {
            PCB *current = ready_queue;
            while (current->next)
                current = current->next;
            current->next = running_process;
        }
        else
        {
            ready_queue = running_process;
        }
    }
}

// 请求资源（修改版）
int request_resource(int pid, int rid, int amount)
{
    if (rid < 0 || rid >= MAX_RESOURCE_TYPES)
        return -1;

    PCB *proc = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        if (processes[i].pid == pid)
        {
            proc = &processes[i];
            break;
        }
    }
    if (!proc)
        return -1;

    RCB *res = &resources[rid];
    if (amount > res->total)
        return -1;

    if (amount <= res->available)
    {
        res->available -= amount;
        proc->resources_held[rid] += amount;
        return 0;
    }
    else
    {
        // 加入等待队列
        proc->state = BLOCKED;
        WaitNode *new_node = malloc(sizeof(WaitNode));
        new_node->proc = proc;
        new_node->amount = amount;
        new_node->next = NULL;

        // 从就绪队列移除
        PCB *prev = NULL;
        PCB *current = ready_queue;
        while (current && current != proc)
        {
            prev = current;
            current = current->next;
        }
        if (current == proc)
        {
            if (prev)
            {
                prev->next = current->next;
            }
            else
            {
                ready_queue = current->next;
            }
        }

        // 添加到资源等待队列
        if (!res->waiting_queue)
        {
            res->waiting_queue = new_node;
        }
        else
        {
            WaitNode *wn = res->waiting_queue;
            while (wn->next)
                wn = wn->next;
            wn->next = new_node;
        }
        return 1;
    }
}

// 释放资源（修改版）
int release_resource(int pid, int rid, int amount)
{
    if (rid < 0 || rid >= MAX_RESOURCE_TYPES)
        return -1;

    PCB *proc = NULL;
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        if (processes[i].pid == pid)
        {
            proc = &processes[i];
            break;
        }
    }
    if (!proc || proc->resources_held[rid] < amount)
        return -1;

    RCB *res = &resources[rid];
    proc->resources_held[rid] -= amount;
    res->available += amount;

    // 处理等待队列
    WaitNode **wn_ptr = &res->waiting_queue;
    while (*wn_ptr)
    {
        WaitNode *current = *wn_ptr;
        if (current->amount <= res->available)
        {
            res->available -= current->amount;
            current->proc->resources_held[rid] += current->amount;
            current->proc->state = READY;

            // 加入就绪队列
            if (!ready_queue)
            {
                ready_queue = current->proc;
            }
            else
            {
                PCB *p = ready_queue;
                while (p->next)
                    p = p->next;
                p->next = current->proc;
            }

            // 移除等待节点
            *wn_ptr = current->next;
            free(current);
            schedule();
        }
        else
        {
            wn_ptr = &(*wn_ptr)->next;
        }
    }
    return 0;
}

// 打印系统状态
void print_status()
{
    printf("\n=== System Status ===\n");

    // 资源状态
    printf("[Resources]\n");
    for (int i = 0; i < MAX_RESOURCE_TYPES; i++)
    {
        printf("R%d: Total=%d Available=%d\n", i, resources[i].total, resources[i].available);
        if (resources[i].waiting_queue)
        {
            printf("  Waiting:");
            WaitNode *wn = resources[i].waiting_queue;
            while (wn)
            {
                printf(" P%d(%d)", wn->proc->pid, wn->amount);
                wn = wn->next;
            }
            printf("\n");
        }
    }

    // 进程状态
    printf("\n[Processes]\n");
    printf("Running: %s\n", running_process ? "P" : "None");
    printf("Ready Queue:");
    PCB *p = ready_queue;
    while (p)
    {
        printf(" P%d", p->pid);
        p = p->next;
    }

    printf("\n\n[Process Details]\n");
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        if (processes[i].pid != -1)
        {
            printf("P%d: State=%s Resources[",
                   processes[i].pid,
                   processes[i].state == READY ? "READY" : processes[i].state == BLOCKED ? "BLOCKED"
                                                                                         : "RUNNING");
            for (int j = 0; j < MAX_RESOURCE_TYPES; j++)
            {
                if (processes[i].resources_held[j] > 0)
                {
                    printf(" R%d=%d", j, processes[i].resources_held[j]);
                }
            }
            printf(" ]\n");
        }
    }
    printf("====================\n\n");
}

// Shell界面
void shell()
{
    char cmd[MAX_CMD_LENGTH];

    printf("OS Shell - Enter commands (help for command list)\n");
    while (1)
    {
        printf("> ");
        fflush(stdout);

        if (!fgets(cmd, MAX_CMD_LENGTH, stdin))
            break;

        if (strcmp(cmd, "\n") == 0)
            continue;

        // 解析命令
        char action[16];
        int pid, rid, amount;

        if (sscanf(cmd, "create") == 0)
        {
            int new_pid = create_process();
            if (new_pid != -1)
            {
                printf("Created process P%d\n", new_pid);
            }
            else
            {
                printf("Error: Process table full\n");
            }
        }
        else if (sscanf(cmd, "request %d %d %d", &pid, &rid, &amount) == 3)
        {
            if (rid >= 0 && rid < MAX_RESOURCE_TYPES && amount > 0)
            {
                int result = request_resource(pid, rid, amount);
                if (result == 0)
                {
                    printf("P%d successfully requested %d R%d\n", pid, amount, rid);
                }
                else if (result == 1)
                {
                    printf("P%d blocked waiting for %d R%d\n", pid, amount, rid);
                }
                else
                {
                    printf("Request failed\n");
                }
            }
            else
            {
                printf("Invalid resource ID or amount\n");
            }
        }
        else if (sscanf(cmd, "release %d %d %d", &pid, &rid, &amount) == 3)
        {
            if (rid >= 0 && rid < MAX_RESOURCE_TYPES && amount > 0)
            {
                if (release_resource(pid, rid, amount) == 0)
                {
                    printf("P%d released %d R%d\n", pid, amount, rid);
                }
                else
                {
                    printf("Release failed\n");
                }
            }
            else
            {
                printf("Invalid resource ID or amount\n");
            }
        }
        else if (strcmp(cmd, "list\n") == 0)
        {
            print_status();
        }
        else if (sscanf(cmd, "kill %d", &pid) == 1)
        {
            terminate_process(pid);
            printf("P%d terminated\n", pid);
        }
        else if (strcmp(cmd, "exit\n") == 0)
        {
            printf("Exiting...\n");
            break;
        }
        else if (strcmp(cmd, "help\n") == 0)
        {
            printf("\nAvailable commands:\n");
            printf("create          - Create new process\n");
            printf("request <pid> <rid> <amount> - Request resources\n");
            printf("release <pid> <rid> <amount> - Release resources\n");
            printf("kill <pid>      - Terminate process\n");
            printf("list            - Show system status\n");
            printf("exit            - Exit shell\n");
            printf("help            - Show this help\n");
        }
        else
        {
            printf("Unknown command. Type 'help' for command list.\n");
        }
    }
}

int main()
{
    init_system();
    shell();
    return 0;
}