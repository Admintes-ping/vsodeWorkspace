<template>
  <div class="client">
    <h2>TCP 客户端</h2>
    <div class="button-group">
      <button @click="sendSyn" :disabled="isConnected" class="btn syn-btn">
        发送 SYN (发起连接)
      </button>
      <button @click="sendData" :disabled="!isConnected" class="btn data-btn">
        发送数据
      </button>
      <button @click="sendFin" :disabled="!isConnected" class="btn fin-btn">
        发送 FIN (关闭连接)
      </button>
    </div>
    <div class="status">
      <p>客户端序列号: <span class="seq">{{ clientSeq }}</span></p>
      <p>服务端确认号: <span class="ack">{{ serverAck }}</span></p>
      <p v-if="isConnected" class="connected">连接状态: 已连接</p>
      <p v-else class="disconnected">连接状态: 未连接</p>
    </div>
  </div>
</template>

<script>
export default {
  props: {
    serverAck: Number,
    serverSeq: Number,
  },
  data() {
    return {
      isConnected: false,
      clientSeq: 0,
    };
  },
  methods: {
    sendSyn() {
      this.clientSeq = Math.floor(Math.random() * 1000);
      this.$emit('sendSyn', this.clientSeq);
    },
    sendData() {
      if (this.serverAck === this.clientSeq + 1) {
        const data = 'Hello, Server!';
        this.$emit('sendData', data);
        this.clientSeq += data.length;
      } else {
        alert('数据发送失败：未收到服务端的确认！');
      }
    },
    sendFin() {
      this.$emit('sendFin', this.clientSeq);
      this.isConnected = false;
    },
  },
  watch: {
    serverAck(newAck) {
      if (newAck === this.clientSeq + 1) {
        this.isConnected = true;
      }
    },
  },
};
</script>

<style scoped>
.client {
  background: #fff;
  padding: 20px;
  border-radius: 10px;
  box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
  width: 45%;
}

h2 {
  color: #555;
}

.button-group {
  margin-bottom: 20px;
}

.btn {
  padding: 10px 20px;
  margin: 5px;
  border: none;
  border-radius: 5px;
  cursor: pointer;
  font-size: 14px;
  transition: background 0.3s ease;
}

.syn-btn {
  background: #4caf50;
  color: white;
}

.syn-btn:disabled {
  background: #a5d6a7;
  cursor: not-allowed;
}

.data-btn {
  background: #2196f3;
  color: white;
}

.data-btn:disabled {
  background: #90caf9;
  cursor: not-allowed;
}

.fin-btn {
  background: #f44336;
  color: white;
}

.fin-btn:disabled {
  background: #ef9a9a;
  cursor: not-allowed;
}

.status {
  margin-top: 20px;
}

.seq, .ack {
  font-weight: bold;
  color: #333;
}

.connected {
  color: #4caf50;
}

.disconnected {
  color: #f44336;
}
</style>