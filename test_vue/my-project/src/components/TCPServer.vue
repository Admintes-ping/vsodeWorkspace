<template>
  <div class="server">
    <h2>TCP 服务端</h2>
    <div class="data-card" v-if="receivedData">
      <p>接收到的数据: <span class="data">{{ receivedData }}</span></p>
    </div>
    <p v-else>等待客户端连接和数据...</p>
    <div class="status">
      <p>服务端序列号: <span class="seq">{{ serverSeq }}</span></p>
      <p>客户端确认号: <span class="ack">{{ clientAck }}</span></p>
    </div>
  </div>
</template>

<script>
export default {
  props: {
    receivedData: String,
    clientSeq: Number,
  },
  data() {
    return {
      serverSeq: 0,
      clientAck: 0,
    };
  },
  methods: {
    sendSynAck() {
      this.serverSeq = Math.floor(Math.random() * 1000);
      this.clientAck = this.clientSeq + 1;
      this.$emit('sendSynAck', this.serverSeq, this.clientAck);
    },
    sendAck() {
      this.clientAck = this.clientSeq + 1;
      this.$emit('sendAck', this.clientAck);
    },
    sendFinAck() {
      this.clientAck = this.clientSeq + 1;
      this.$emit('sendFinAck', this.clientAck);
    },
  },
  watch: {
    clientSeq(newSeq) {
      if (newSeq > 0 && this.serverSeq === 0) {
        this.sendSynAck();
      } else if (newSeq > 0 && this.serverSeq > 0) {
        this.sendAck();
      }
    },
  },
};
</script>

<style scoped>
.server {
  background: #fff;
  padding: 20px;
  border-radius: 10px;
  box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
  width: 45%;
}

h2 {
  color: #555;
}

.data-card {
  background: #e3f2fd;
  padding: 15px;
  border-radius: 5px;
  margin-bottom: 20px;
}

.data {
  font-weight: bold;
  color: #2196f3;
}

.status {
  margin-top: 20px;
}

.seq, .ack {
  font-weight: bold;
  color: #333;
}
</style>