import App from './App'

// 引入全局存储
import store from '@/store';
// 引入全局配置
import $mAssetsPath from '@/config/assets.config.js';
import $mConfig from '@/config/index.config.js';
import $mRoutesConfig from '@/config/routes.config.js';
import $mConstDataConfig from '@/config/constData.config.js';
import $mSettingConfig from '@/config/setting.config.js';

// 引入全局方法
// 全局组件

// 挂载全局自定义方法
Vue.prototype.$mStore = store;

// Vue.prototype.$http = http;
Vue.prototype.$mAssetsPath = $mAssetsPath;
Vue.prototype.$mRoutesConfig = $mRoutesConfig;
Vue.prototype.$mConstDataConfig = $mConstDataConfig;
Vue.prototype.$mRoutesConfig = $mRoutesConfig;
Vue.prototype.$mSettingConfig = $mSettingConfig;


// 挂载全局自定义方法
Vue.prototype.$mStore = store;

Vue.mixin({
	computed: {
		themeColor: {
			get () {
				return store.getters.themeColor;
			},
			set (val) {
				store.state.themeColor = val;
			}
		}
	}
});

// #ifndef VUE3
import Vue from 'vue'
import './uni.promisify.adaptor'
Vue.config.productionTip = false
App.mpType = 'app'
const app = new Vue({
  ...App,
  store:store
})
app.$mount()
// #endif

// #ifdef VUE3
import { createSSRApp } from 'vue'
export function createApp() {
  const app = createSSRApp(App)
  return {
    app
  }
}
// #endif