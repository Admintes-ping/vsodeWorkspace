import { createApp } from 'vue'
import './style.css'
import App from './App.vue'
import 'ol/ol.css';

// 引入 Element Plus
import ElementPlus from 'element-plus'
import 'element-plus/dist/index.css' // 导入 Element Plus 样式

const app = createApp(App)

// 使用 Element Plus 插件
app.use(ElementPlus)

app.mount('#app')
