<template>
	<view class="about">
		<view>
			<view style=" color: gray;opacity: 0.9;;font-size: 33upx;">
				<text>昵称</text>
				<text style="margin-left: 90upx;font-size: 33upx;">{{loginInfo.name}}</text>
			</view>
			<view class="underline"></view>
		</view>
		<view v-for="(item, index) in list" :key="item.title" class="input-group">
			<text class="title">{{item.title}}</text>
			<input type="safe-password" class="input-field" v-model="inputValues[index]"
				:placeholder="index === list.length - 1 ? '再次输入确认' : getPlaceholder(item.title)" />
		</view>
		<view @tap="complete">
			<button class="button">完成</button>
		</view>
	</view>
</template>

<script>
	import {
		mapState,
		mapMutations
	} from 'vuex';

	export default {
		computed: {
			...mapState({
				loginInfo: state => state.login
			})
		},
		data() {
			return {
				list: [{
					title: "原密码"
				}, {
					title: "新密码"
				}, {
					title: "确认密码"
				}],
				inputValues: ['','',''] // 用于存贮输入的值
			}
		},
		onShow() {

		},
		methods: {
			getPlaceholder(title) {
				return `请输入${title}`;
			},
			complete() {
				const oldPassword = this.inputValues[0];
				const newPassword = this.inputValues[1];
				const confirmPassword = this.inputValues[2];
				if(this.loginInfo.password!=oldPassword){
					uni.showToast({
						title: '与原密码不匹配',
						icon: 'none'
					});
				}else{
					uni.showToast({
						title: '请输入原密码',
						icon: 'none'
					});
				}
				if(newPassword===confirmPassword){
					uni.showToast({
						title: '修改成功',
						icon: 'success',
						duration: 2000 // 提示显示的时间，单位为毫秒
					});
				}
			}
		}
	}
</script>

<style lang='scss'>
	.button {
		margin-top: 100upx;
		margin-left: 10upx;
		margin-right: 10upx;
		background-color: #1cbbb4;
		/* 按钮背景颜色 */
		color: white;
		/* 按钮文字颜色 */
		transition: background-color 0.3s;
		/* 背景颜色变化过渡 */

	}

	.underline {
		border-bottom: 1px solid #ccc;
		/* 设置下划线的颜色和宽度 */
		width: 100%;
		/* 下划线宽度为100% */
		margin-top: 5px;
		/* 与输入框之间的间距 */
	}

	.title {

		color: black;
		/* 设置文字颜色 */
		font-size: 33upx; /* 设置标题字体大小 */
	}

	.input-field {
		border: none;
		/* 取消默认边框 */
		border-bottom: 1px solid #ccc;
		/* 添加下横线 */
		flex: 1;
		/* 输入框占据剩余空间 */
		padding: 5px;
		/* 内边距 */
		outline: none;
		/* 去掉聚焦时的轮廓 */
		margin-left: auto;
		/* 将输入框推到右侧 */
		max-width: 590upx;
		min-width: 590upx;
		/* 设置最小宽度 */
		transition: border-bottom 0.3s;
		/* 平滑过渡效果 */
		font-size: 30upx; /* 设置输入框字体大小 */

	}

	/* 当输入框聚焦时改变下划线颜色 */
	.input-field:focus {
		border-bottom: 1px solid #1cbbb4;
		/* 设置为天青色 */
	}

	.input-group {
		display: flex;
		/* 使用 Flexbox 布局 */
		align-items: center;
		/* 垂直居中对齐 */
		margin-top: 14upx;
		margin-bottom: 15upx;
		/* 每行之间的间距 */

	}



	.about {
		padding: 20upx 0;
		margin-top: 30%;
		margin-left: 15upx;
		margin-right: 10upx;

		.history-section {
			padding: 30upx 0 0;
			margin-top: 20upx;
			background: #fff;
			border-radius: 10upx;

			.sec-header {
				display: flex;
				align-items: center;
				font-size: $font-base;
				color: $font-color-dark;
				line-height: 40upx;
				margin-right: 30upx;
			}

			.qucode-wrapper {
				padding: $spacing-lg 0;
				text-align: center;

				.qrcode {
					height: 280upx;
				}

				.info {
					display: block;
				}
			}
		}
	}
</style>