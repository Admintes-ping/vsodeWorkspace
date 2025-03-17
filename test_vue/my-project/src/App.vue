<template>
  <div id="app">
    <!-- <HelloWorld/> -->
    <div>
      <h1>TCP 工作原理模拟</h1>
      <div class="container">
        <TCPClient
          @sendSyn="handleSyn"
          @sendData="handleData"
          @sendFin="handleFin"
          :serverAck="serverAck"
          :serverSeq="serverSeq"
        />
        <TCPServer
          :receivedData="serverData"
          @sendSynAck="handleSynAck"
          @sendAck="handleAck"
          @sendFinAck="handleFinAck"
          :clientSeq="clientSeq"
        />
      </div>
    </div>
  </div>
</template>

<script>
// import HelloWorld from './components/HelloWorld.vue'//模拟三角函数绘制图
import TCPClient from "./components/TCPClient.vue";
import TCPServer from "./components/TCPServer.vue";
export default {
  name: "App",
  components: {
    // HelloWorld,
    TCPClient,
    TCPServer,
  },
  data() {
    return {
      serverData: null, // 服务端接收到的数据
      clientSeq: 0, // 客户端的序列号
      serverSeq: 0, // 服务端的序列号
      serverAck: 0, // 服务端的确认号
    };
  },
  methods: {
     // 处理客户端发送的 SYN
    handleSyn(seq) {
      this.clientSeq = seq;
    },
    // 处理服务端发送的 SYN-ACK
    handleSynAck(seq, ack) {
      this.serverSeq = seq;
      this.serverAck = ack;
    },
    // 处理客户端发送的数据
    handleData(data) {
      this.serverData = data;
    },
    // 处理服务端发送的 ACK
    handleAck(ack) {
      this.serverAck = ack;
    },
    // 处理客户端发送的 FIN
    handleFin(seq) {
      this.clientSeq = seq;
    },
    // 处理服务端发送的 FIN-ACK
    handleFinAck(ack) {
      this.serverAck = ack;
    },
  },
};
</script>

<style>
#app {
  display: flex; /* 使用 Flexbox 布局 */
  justify-content: center; /* 水平居中 */
  align-items: center; /* 垂直居中 */
  height: 100vh; /* 设置父组件高度为视口高度 */
  margin-top: 0; /* 移除 margin-top */
}
.container {
  display: flex;
  justify-content: space-around;
}
</style>
