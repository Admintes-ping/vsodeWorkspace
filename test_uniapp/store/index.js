/**
 *@des 
 *@author yiiframe 21931118@qq.com
 *@blog http://www.yiiframe.com
 *@date 2019/1/1 07:25:00
 */
import Vue from 'vue';
import Vuex from 'vuex';
import $mConstDataConfig from '@/config/constData.config';
Vue.use(Vuex);
const ACCESSTOKEN = uni.getStorageSync('accessToken') || '';
const REFERRER = uni.getStorageSync('referrer') || '';
const USER = uni.getStorageSync('user') || {};
const REFRESHTOKEN = uni.getStorageSync('refreshToken') || '';
const GLOBALCONFIG = uni.getStorageSync('globalConfig') || {};
const CARTNUM = uni.getStorageSync('cartNum') || 0;
const NOTIFYNUM = uni.getStorageSync('notifyNum') || 0;
const IMHISTORY = uni.getStorageSync('imHistory') || [];
const IMNOREAD = uni.getStorageSync('imNoRead') || 0;
const THEMECOLOR = uni.getStorageSync('themeColor') || {
	title: '天青',
	name: 'cyan',
	color: '#1cbbb4'
};
const store = new Vuex.Store({
	state: {
		// 用户信息
		login: {
			name: '',
			password:''
		},
		content: '',
		themeColor: THEMECOLOR
	},
	getters: {
		getLogin(state) {
			return state.login;
		},
		content:state =>{
			return state.content;
		},
		// 全局配置
		themeColor: state => {
			return state.themeColor;
		},
		// 全局配置
		globalConfig: state => {
			return state.globalConfig;
		},
	
	},
	mutations: {
		setLogin(state, loginData) {
			state.login.name = loginData.name;
			state.login.password=loginData.password
		},
		setname(state, name) {
			state.login.name = name;
		},
		setThemeColor(state, val) {
			state.themeColor = val;
			uni.setStorageSync('themeColor', val);
		}
	},
	actions: {
		updateLogin({
			commit
		}, loginData) {
			commit('setLogin', loginData);
		}
	}
});

export default store;