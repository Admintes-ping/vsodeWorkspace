<template>
	<view class="user">
		<view class="user-section">
			<image src="../../static/background/user-bg.png" class="bg"></image>
			<view class="user-info-box">
				<view class="portrait-box" @tap="uploadImage">
					<image class="portrait" :src="imageUrl ? imageUrl : '../../static/background/missing-face.png'" ></image>
					<text class="username">
						{{loginInfo.name}}
					</text>
				</view>
			</view>
		</view>

		<!-- 个人中心 内容区-->
		<view class="cover-container" :style="[
			{
				transform: coverTransform,
				transition: coverTransition
			}
		]" @touchstart="coverTouchstart" @touchmove="coverTouchmove" @touchend="coverTouchend">
			<image class="arc" src='../../static/background/arc.png'></image>
			<view class="promotion-center">
				<oa-list-cell icon="iconfenlei" :iconColor="themeColor.color" navigateType=""
					:title="applicationList.title"></oa-list-cell>
				<!-- 个人中心 -->
				<view class="order-section">
					<view class="category" v-for="(item, index) in applicationList.list" :key="index"
						@tap.stop="navTo(item.url)">
						<view class="order-item">
							<view class="img">
								<text class="iconfont" :class="[item.icon, 'text-'+themeColor.name]"></text>
							</view>
							<view class="text">{{ item.title }}</view>
							<oa-badge v-if="item.num>0" type="error" size="small" class="badge" :text="item.num">
							</oa-badge>
						</view>
					</view>
				</view>
			</view>
			<!-- 个人资料 -->
			<view class="set">
				<view class="list-cell b-b" :class="{ 'm-t': item.class === 'mT' }" v-for="item in setList"
					:key="item.title" @tap="navTo(item.url)" hover-class="cell-hover" :hover-stay-time="50">
					<text class="cell-tit">{{ item.title }}</text>
					<!-- <text class="cell-tip">{{ item.content }}</text> -->
					<text class="cell-more iconfont iconyou"></text>
				</view>
			</view>
			<view class="list-cell log-out-btn" @tap="toLogout">
				<text class="cell-tit" style="color: #1cbbb4;">退出登录</text>
			</view>
		</view>
	</view>
</template>

<script>
	import {
		mapState
	} from 'vuex';
	import $mAssetsPath from '@/config/assets.config';
	let startY = 0,
		moveY = 0,
		pageAtTop = true;
	export default {
		computed: {
			...mapState({
				loginInfo: state => state.login
			})
		},
		data() {
			return {
				applicationList: {
					"title": "个人管理",
					"list": [{
						"title": "我的公告",
						"name": "Announce",
						"icon": "icontongzhi",
						"url": "/pages/application/Announce/index",
						"num": 0
					}, {
						"title": "我的日程",
						"name": "Calendar",
						"icon": "iconricheng",
						// "url": "/pages/application/Calendar/index",
						"num": 0
					}, {
						"title": "我的日志",
						"name": "DailyWork",
						"icon": "iconzongjie",
						// "url": "/pages/application/DailyWork/index",
						"num": 0
					}, {
						"title": "我的消息",
						"name": "Message",
						"icon": "iconxiaoxi7",
						// "url": "/pages/application/Message/index",
						"num": 0
					}, {
						"title": "我的总结",
						"name": "Summary",
						"icon": "iconicon-test21",
						// "url": "/pages/application/Summary/index",
						"num": 0
					}]
				},
				themeList: this.$mConstDataConfig.themeList,
				userBg: this.$mAssetsPath.userBg,
				coverTransform: 'translateY(0px)',
				coverTransition: '0s',
				setList: this.$mConstDataConfig.setList,
				imageUrl:''
			}
		},
		onLoad() {
			
		},
		onNavigationBarButtonTap(e) {
			const index = e.index;
			if (index === 0) {
				this.navTo('/pages/set/set');
			}
		},
		methods: {
			uploadImage() {
				const _this = this;
				uni.chooseImage({
					count: 1,
					sizeType: ['original', 'compressed'],
					sourceType: ['album'],
					success: (res) => {
						this.imageUrl = res.tempFilePaths[0]; // 直接将选择的图片路径赋值给 avatarUrl
					},
					fail: function(err) {
						console.error('选择图片失败:', err);
					}
				});
			},
			navTo(url) {
				if (url) {
					uni.navigateTo({
						url: url // 目标页面路径
					});
				} else {
					uni.showToast({
						title: '该页面暂未开放',
						icon: 'none'
					});
				}
			},
			eventClick() {
				this.$emit('eventClick');
				console.log(this.$emit('eventClick'))
			},
			toLogout() {
				uni.showModal({
					content: '确定要退出登录么',
					success: e => {
						if (e.confirm) {
							uni.reLaunch({
								url: '/pages/index/index'
							});
						}
					}
				});
			},
			coverTouchstart(e) {
				if (pageAtTop === false) {
					return;
				}
				this.coverTransition = 'transform .1s linear';
				startY = e.touches[0].clientY;
			},
			coverTouchmove(e) {
				moveY = e.touches[0].clientY;
				let moveDistance = moveY - startY;
				if (moveDistance < 0) {
					this.moving = false;
					return;
				}
				this.moving = true;
				if (moveDistance >= 80 && moveDistance < 100) {
					moveDistance = 80;
				}
				if (moveDistance > 0 && moveDistance <= 80) {
					this.coverTransform = `translateY(${moveDistance}px)`;
				}
			},
			coverTouchend() {
				if (this.moving === false) {
					return;
				}
				this.moving = false;
				this.coverTransition = 'transform 0.3s cubic-bezier(.21,1.93,.53,.64)';
				this.coverTransform = 'translateY(0px)';
			},
		}
	}
</script>

<style lang="scss" scoped>
	page {
		background-color: $page-color-base;
	}

	.icon .mix-list-cell.b-b:after {
		left: 90upx;
	}

	.mix-list-cell {
		display: flex;
		align-items: baseline;
		padding: 20upx $page-row-spacing;
		line-height: 60upx;
		position: relative;

		&.cell-hover {
			background: #fafafa;
		}

		&.b-b:after {
			left: 30upx;
		}

		.cell-icon {
			align-self: center;
			width: 56upx;
			max-height: 60upx;
			font-size: 38upx;
		}

		.cell-more {
			align-self: center;
			font-size: 30upx;
			color: $font-color-base;
			margin-left: $uni-spacing-row-sm;
		}

		.cell-tit {
			flex: 1;
			font-size: $font-base;
			color: $font-color-dark;
			margin-right: 10upx;
		}

		.cell-tip {
			font-size: $font-sm + 2upx;
		}
	}

	.user {
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

		.order-section {
			@extend %section;
			padding: 28upx 0;

			.order-item {
				@extend %flex-center;
				width: 120upx;
				height: 120upx;
				border-radius: 10upx;
				font-size: $font-sm;
				color: $font-color-dark;
				position: relative;
			}

			.badge {
				position: absolute;
				top: 0;
				right: 4upx;
			}

			.iconfont {
				font-size: 48upx;
			}

			.icon-shouhoutuikuan {
				font-size: 44upx;
			}
		}

		.no-foot-print {
			text-align: center;
			padding: 48upx 0;

			.no-foot-print-icon {
				font-size: $font-lg + 2upx;
				margin-right: 10upx;
			}
		}

		.set {
			padding: $spacing-base 0;

		}

		.cu-list.card-menu {
			margin: $spacing-base 0;

			.title {
				margin-left: $spacing-base;
			}
		}

		.user-section {
			height: 520upx;
			padding: 100upx 30upx 0;
			position: relative;
			background-color: #1cbbb4;

			.bg {
				position: absolute;
				left: 0;
				top: 0;
				width: 100vw;
				height: 60vw;
				opacity: 0.84;
			}

			.user-info-box {
				height: 180upx;
				display: flex;
				align-items: center;
				position: relative;
				z-index: 1;
				justify-content: space-between;

				.portrait-box {//修改图片变成圆的
					display: flex;
					align-items: center;

					.portrait {
						width: 130upx;
						height: 130upx;
						border: 5upx solid #fff;
						border-radius: 50%;
					}

					.username {
						font-size: $font-lg + 6upx;
						color: $color-white;
						margin-left: 20upx;
					}

					button {
						background-color: transparent;
						font-size: $font-lg + 6upx;
						color: $font-color-dark;
						border: none;
					}

					button::after {
						border: none;
					}
				}
			}

			.vip-card-box {
				display: flex;
				flex-direction: column;
				color: #f7d680;
				height: 240upx;
				background: url('/static/vip-card.png');
				background-size: 100% 100%;
				border-radius: 16upx 16upx 0 0;
				overflow: hidden;
				position: relative;
				padding: 20upx 24upx;

				.b-btn {
					position: absolute;
					right: 24upx;
					top: 24upx;
					width: 160upx;
					height: 40upx;
					text-align: center;
					line-height: 40upx;
					font-size: 22upx;
					color: #36343c;
					border-radius: 20px;
					background: linear-gradient(to left, #f9e6af, #ffd465);
					z-index: 1;
				}

				.tit {
					font-size: $font-base + 2upx;
					color: #f7d680;
					margin-bottom: 28upx;

					.iconfont {
						color: #f6e5a3;
						display: inline-block;
						margin-right: 16upx;
					}
				}
			}
		}

		.cover-container {
			margin-top: -150upx;
			padding: 0 30upx 20upx;
			position: relative;
			background-color: $page-color-base;

			.arc {
				position: absolute;
				left: 0;
				top: -34upx;
				width: 100%;
				height: 36upx;
			}

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

			.tj-sction {
				@extend %section;
				display: flex;

				.tj-item {
					@extend %flex-center;
					flex: 1;
					flex-direction: column;
					margin: 30upx 0;
					font-size: $font-sm;
					color: #75787d;
					/*border-right: 2upx solid rgba(0, 0, 0, 0.2);*/
				}

				/*.tj-item:last-child {*/
				/*border-right: none;*/
				/*}*/
				.num {
					font-size: $font-base;
				}

				.red {
					color: $base-color;
				}
			}

		}
	}

	%flex-center {
		display: flex;
		flex-direction: column;
		justify-content: center;
		align-items: center;
	}

	%section {
		justify-content: space-around;
		display: flex;
		align-content: center;
		background: #fff;
		border-radius: 10upx;
	}
</style>