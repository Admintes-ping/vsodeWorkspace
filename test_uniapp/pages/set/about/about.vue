<template>
	<view class="about" style="background: #ffffff;">
		<view class="bg">
			<image :src="logo" class="img"></image>
		</view>
		<view style="margin-bottom: 4%;text-align: center; margin-top: 5%;">
			<text>{{appName}}</text>
			<view>
				<text>版本 {{versionName}}</text>
			</view>
		</view>
		<view v-for="item in navlist" :key="item.title" class="list-cell b-b" @tap="navTo(item.url, item.identifier)">
			<text class="cell-tit">{{item.title}}</text>
			<text class="cell-tip">{{ item.content }}</text>
			<text class="cell-more iconfont iconyou"></text>
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				aboutInfo: {},
				navlist: [{
					title: '关于我们',
					url: '/pages/set/aboutMe',
				}, {
					title: '注册协议',
					url: '/pages/set/register',
				}, {
					title: '隐私协议',
					url: '/pages/set/privacy/privacy',
				}],
				// hostUrl: this.$mConfig.hostUrl,
				appName: this.$mSettingConfig.appName,
				logo: this.$mAssetsPath.logo,
				versionName: ''
			}
		},
		onShow() {
			uni.setNavigationBarColor({
				frontColor: '#ffffff',
				backgroundColor: "#1cbbb4",
				animation: {
					duration: 400,
					timingFunc: 'easeIn'
				}
			})
		},
		onLoad() {

			this.versionName = this.$root.versionName || '未知版本'; // 从根组件获取版本名称
		},
		methods: {
			navTo(url) {
				// 使用 uni.navigateTo() 方法导航到相应的页面
				uni.navigateTo({
					url: url
				});
			}
		}
	}
</script>


<style lang="scss">
	page {
		position: relative;
		background-color: #ffffff;
	}

	/*关于办公*/
	.about {
		margin-top: 30%;
		/* 垂直排列 */
		align-items: center;
		/* 水平居中 */
		padding: 20upx 0;

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
				margin-left: 30upx;

				.iconfont {
					font-size: 44upx;
					color: #5eba8f;
					margin-right: 16upx;
					line-height: 40upx;
				}
			}

			.qrcode-wrapper {
				padding: $spacing-lg 0;
				text-align: center;

				.qrcode-img-wrapper {
					display: flex;
					justify-content: center;
					align-items: center;
				}

				.qrcode {
					height: 280upx;
				}

				.qrcode-img {
					width: 300upx;
					height: 300upx;

					image {
						width: 300upx;
						height: 300upx;
					}
				}

				.info {
					display: block;
				}
			}
		}


	}

	.bg {
		/* 背景颜色 */
		width: 100px;
		/* 盒子的宽度 */
		height: 100px;
		/* 盒子的高度 */
		margin: auto;
	}

	.img {
		max-width: 100%;
		/* 保证图片不会超出盒子的宽度 */
		max-height: 100%;
		/* 保证图片不会超出盒子的高度 */
	}
</style>