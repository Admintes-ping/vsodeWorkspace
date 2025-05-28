<template>
  <view class="countdown-container">
    <text class="countdown-text">{{ formattedTime }}</text>
    <view class="button-group">
      <button @click="startCountdown" :disabled="isRunning">开始</button>
      <button @click="pauseCountdown" :disabled="!isRunning">暂停</button>
      <button @click="resetCountdown">重置</button>
    </view>
  </view>
</template>

<script>
export default {
  data() {
    return {
      totalSeconds: 3600, // 1小时 = 3600秒
      remainingSeconds: 3600,
      timer: null,
      isRunning: false,
      lastUpdateTime: 0
    }
  },
  computed: {
    formattedTime() {
      const hours = Math.floor(this.remainingSeconds / 3600)
      const minutes = Math.floor((this.remainingSeconds % 3600) / 60)
      const seconds = this.remainingSeconds % 60
      
      return `${this.pad(hours)}:${this.pad(minutes)}:${this.pad(seconds)}`
    }
  },
  methods: {
    pad(num) {
      return num < 10 ? '0' + num : num
    },
    
    startCountdown() {
      if (this.isRunning) return
      
      this.isRunning = true
      this.lastUpdateTime = Date.now()
      
      this.timer = setInterval(() => {
        const now = Date.now()
        const elapsed = Math.floor((now - this.lastUpdateTime) / 1000)
        
        if (elapsed >= 1) {
          this.remainingSeconds = Math.max(0, this.remainingSeconds - elapsed)
          this.lastUpdateTime = now
          
          if (this.remainingSeconds <= 0) {
            this.stopCountdown()
            uni.showToast({
              title: '倒计时结束',
              icon: 'none'
            })
          }
        }
      }, 200) // 使用较短的间隔提高准确性
    },
    
    pauseCountdown() {
      this.stopCountdown()
    },
    
    resetCountdown() {
      this.stopCountdown()
      this.remainingSeconds = this.totalSeconds
    },
    
    stopCountdown() {
      if (this.timer) {
        clearInterval(this.timer)
        this.timer = null
      }
      this.isRunning = false
    }
  },
  
  beforeDestroy() {
    this.stopCountdown()
  }
}
</script>

<style>
.countdown-container {
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  height: 100vh;
}

.countdown-text {
  font-size: 48px;
  margin-bottom: 30px;
  font-family: monospace;
}

.button-group {
  display: flex;
  gap: 15px;
}

button {
  padding: 10px 20px;
  font-size: 16px;
}
</style>