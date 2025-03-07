<template>
	<view class="notify">
		<view class="promotion-center">
			<oa-list-cell icon="icongonggao" iconColor="#1cbbb4"
				@eventClick="navTo('/pages/application/Announce/index')" title="通知公告"></oa-list-cell>
		</view>
		<view class="dialog-box" v-if="showOptions">
			<view v-for="item in addlist" :key="item.id" @tap="navTo(item.url)" class="addtitle">{{item.title}}</view>
			<view class="dialog-arrow"></view>
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				showOptions: false,
				addlist: [{
					"title": "添加公告",
					"id": "0",
					"url": "/pages/application/Announce/detail"
				}, {
					"title": "添加公告",
					"id": "1",
					"url": " "
				}, {
					"title": "添加公告",
					"id": "2",
					"url": " "
				}]

			}
		},
		mounted() {
			/* 			// uni.createSelectorQuery().select('.uni-page-head .uni-title .uni-icon').boundingClientRect(function(rect) {
						// 	console.log(rect); // 输出按钮的位置信息
						// }).exec();
						// const systemInfo = uni.getSystemInfoSync();
						// this.navBarHeight = systemInfo.statusBarHeight + 44; // 根据实际情况调整
						// console.log(this.navBarHeight) */
		},
		onNavigationBarButtonTap(e) {
			this.showOptions = !this.showOptions;
		},
		methods: {
			navTo(url) {
				uni.navigateTo({
					url: url // 目标页面路径
				});
				if (url == " ") {
					uni.showToast({
						title: '该按钮未启动',
						icon: 'none'
					});
				}
			},
			is_tap(id) {
				console.log("点击的项的 ID:", id)
			}
		},
	}
</script>

<style lang="scss">
	page {
		background-color: $page-color-base;
	}

	.addtitle {
		font-size: 17px;
	}

	.dialog-box {
		position: absolute;
		margin-top: -16%;
		left: 74%;
		z-index: 999999;
		background-color: rgba(159, 159, 159, 0.8);
		/* 透明背景色 */
		border-radius: 8px;
		/* 圆角 */
		padding: 10px;
		max-width: 100px;
		/* 最大宽度 */
	}


	.dialog-arrow {
		z-index: 999999;
		margin-top: -18%;
		position: absolute;
		bottom: 100%;
		/* 将三角形放在对话框上方 */
		left: 92%;
		/* 三角形的位置 */
		margin-left: -5px;
		/* 调整三角形位置 */
		width: 0;
		height: 0;
		border-left: 5px solid transparent;
		/* 左边透明 */
		border-right: 5px solid transparent;
		/* 右边透明 */
		border-bottom: 5px solid rgba(159, 159, 159, 0.8);
		/* 三角形颜色 */
	}

	.notify {

		.promotion-center {
			background: #fff;
			margin-bottom: 20upx;

			/*分类列表*/
			.category-list {
				width: 100%;
				padding: 0 0 30upx 0;
				border-bottom: solid 2upx #f6f6f6;
				display: flex;
				flex-wrap: wrap;

				.category {
					width: 33.3%;
					margin-top: 50upx;
					display: flex;
					justify-content: center;
					flex-wrap: wrap;

					.img {
						width: 100%;
						display: flex;
						justify-content: center;

						.iconfont {
							font-size: $font-lg + 24upx;
						}
					}

					.text {
						width: 100%;
						display: flex;
						justify-content: center;
						font-size: 24upx;
						color: #3c3c3c;
					}

					.share-btn {
						height: 142upx;
						text-align: left;
						background: none;
						padding: 0;
						margin: 0;
					}

					.share-btn:after {
						border: none;
						border-radius: none;
					}
				}
			}
		}
	}
</style>