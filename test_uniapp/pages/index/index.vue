<template>
	<view class="login">
		<block>
			<view class="container">
				<!--插画-->
				<view class="right-top-sign"></view>
				<!-- 设置白色背景防止软键盘把下部绝对定位元素顶上来盖住输入框等 -->
				<view class="wrapper">
					<view class="left-top-sign">LOGIN</view>
					<view class="welcome">
						欢迎进入！
					</view>
					<view class="input-content">
						<view class="input-item">
							<text class="tit">昵称</text>
							<input type="nickname" name="name" v-model="login.name" placeholder="请输入昵称"
								maxlength="11" />
						</view>
						<view class="input-item">
							<text class="tit">密码</text>
							<input name="password" type="password" v-model="login.password" placeholder="请输入密码"
								maxlength="10" />
						</view>
						<button class="confirm-btn" @tap="logname">
							登录
						</button>
					</view>
				</view>
				<view class="register-section">
					<text @tap="retrieve">找回密码</text>
				</view>
			</view>
		</block>
	</view>
</template>

<script>
	import {
		mapState,
		mapActions
	} from 'vuex';
	export default {
		computed: {
			...mapState({
				loginInfo: state => state.login
			})
		},
		data() {
			return {
				login: {
					name: '',
					password: ''
				},
			};
		},
		onLoad() {

		},
		methods: {
			...mapActions(['updateLogin']),
			retrieve() {
				uni.showToast({
					title: '该页面暂未开放',
					icon: 'none'
				});
			},
			logname() {
				const loginData = {
					name: this.login.name,
					password:this.login.password
				};
				// 更新 Vuex store 中的 login 数据
				this.updateLogin(loginData);
				// console.log(this.$store.state.login)

				if (this.login.password) {
					uni.switchTab({
						url: '../home/home',
						animationType: 'pop-in',
						animationDuration: 200
					});
				} else {
					if (this.login.name == '') {
						uni.showToast({
							title: '请输入昵称',
							icon: 'none',
							duration: 2000 // 提示显示的时间，单位为毫秒
						});
					} else {
						uni.showToast({
							title: '登录失败',
							icon: 'error', // 也可以是 'none', 'loading', 'error'
							duration: 1000 // 持续时间，单位为毫秒
						});
					}
				}
			},

		},
		onLoad() {

		}
	}
</script>

<style lang="scss" >
page {
		background: $color-white;
	}
	
	.confirm-btn{
		height: 80upx;
		line-height: 80upx;
		background-color: #1cbbb4;
		border-radius: 40upx;
		color: floralwhite;
	}
	.container {
		padding-top: 115px;
		position: relative;
		width: 100vw;
		overflow: hidden;
		background: #fff;

		.wrapper {
			position: relative;
			z-index: 90;
			background: #fff;
			padding-bottom: 40upx;
		}

		.back-btn {
			position: absolute;
			left: 40upx;
			z-index: 9999;
			padding-top: var(--status-bar-height);
			top: 40upx;
			font-size: 40upx;
			color: $font-color-dark;
		}

		.left-top-sign {
			font-size: 120upx;
			color: $page-color-base;
			position: relative;
			left: -16upx;
		}

		.right-top-sign {
			position: absolute;
			top: 80upx;
			right: -30upx;
			z-index: 95;

			&:before,
			&:after {
				display: block;
				content: '';
				width: 400upx;
				height: 80upx;
				background: #b4f3e2;
			}

			&:before {
				transform: rotate(50deg);
				border-radius: 0 50px 0 0;
			}

			&:after {
				position: absolute;
				right: -198upx;
				top: 0;
				transform: rotate(-50deg);
				border-radius: 50px 0 0 0;
				/* background: pink; */
			}
		}

		.left-bottom-sign {
			position: absolute;
			left: -270upx;
			bottom: -320upx;
			border: 100upx solid #d0d1fd;
			border-radius: 50%;
			padding: 180upx;
		}

		.welcome {
			position: relative;
			left: 50upx;
			top: -90upx;
			font-size: 46upx;
			color: #555;
			text-shadow: 1px 0px 1px rgba(0, 0, 0, 0.3);
		}

		.input-content {
			padding: 0 60upx;
		}

		.input-item {
			display: flex;
			flex-direction: column;
			align-items: flex-start;
			justify-content: center;
			padding: 0 30upx;
			background: $page-color-light;
			height: 120upx;
			border-radius: 4px;
			margin-bottom: 50upx;

			&:last-child {
				margin-bottom: 0;
			}

			.tit {
				height: 50upx;
				line-height: 56upx;
				font-size: $font-sm + 2upx;
				color: $font-color-base;
			}

			input {
				height: 60upx;
				font-size: $font-base + 2upx;
				color: $font-color-dark;
				width: 100%;
			}
		}

		.input-item-sms-code {
			position: relative;
			width: 100%;

			.sms-code-btn {
				position: absolute;
				color: #111;
				right: 20upx;
				bottom: 20upx;
				font-size: 28upx;
			}

			.sms-code-resend {
				color: #999;
			}

			.sms-code-btn:after {
				border: none;
				background-color: transparent;
			}
		}

		.forget-section {
			font-size: $font-sm + 2upx;
			color: $font-color-spec;
			text-align: center;
			margin-top: 40upx;
		}

		.register-section {
			margin: 30upx 0 50upx 0;
			width: 100%;
			font-size: $font-sm + 2upx;
			color: $font-color-base;
			text-align: center;

			text {
				color: $font-color-spec;
				margin-left: 10upx;
			}

			text:first-child {
				margin-right: 10upx;
			}
		}

		.btn-group {
			display: flex;
			margin-bottom: 20upx;
		}
	}

	.login-type-2 {
		width: 100%;
		position: relative;

		.back-btn {
			position: absolute;
			left: 40upx;
			z-index: 9999;
			padding-top: var(--status-bar-height);
			top: 40upx;
			font-size: 48upx;
			color: $color-white;
		}

		.login-top {
			height: 460upx;
			position: relative;

			.desc {
				position: absolute;
				top: 200upx;
				left: 40upx;
				font-size: 48upx;

				.title {
					font-size: 48upx;
				}
			}

			.login-pic {
				position: absolute;
				width: 220upx;
				height: 270upx;
				right: 30upx;
				top: 100upx;
			}
		}

		.login-type-content {
			position: relative;
			top: -72upx;

			.login-bg {
				width: 94vw;
				height: 94vw;
				margin: 0 3vw;
			}

			.main {
				width: 94vw;
				position: absolute;
				top: 0;
				left: 3vw;

				.nav-bar {
					display: flex;
					height: 100upx;
					justify-content: center;
					align-items: center;
					position: relative;
					z-index: 10;

					.nav-bar-item {
						flex: 1;
						display: flex;
						height: 100%;
						line-height: 96upx;
						font-size: $font-lg;
						display: flex;
						margin: 0 120upx;
						justify-content: center;
					}

					.nav-bar-item-active {
						border-bottom: 5upx solid;
					}
				}

				.login-type-form {
					width: 80%;
					margin: 50upx auto;

					.input-item {
						position: relative;
						height: 90upx;
						line-height: 90upx;
						margin-bottom: $spacing-lg;

						.iconfont {
							font-size: 50upx;
							position: absolute;
							left: 0;
						}

						.login-type-input {
							height: 90upx;
							padding-left: 80upx;
							border-bottom: 1upx solid rgba(0, 0, 0, .1);
						}

						.sms-code-btn,
						sms-code-resend {
							width: 240upx;
							font-size: $font-base - 2upx;
						}
					}
				}

				.login-type-tips {
					padding: 0 50upx;
					display: flex;
					justify-content: space-between;
				}

				.confirm-btn {
					height: 80upx;
					line-height: 80upx;
				}
			}
		}

		.login-type-bottom {
			width: 100%;
			padding-bottom: 30upx;
			text-align: center;
			font-size: $font-lg;
		}
	}
</style>