<template>
	<view>
		<view class="set">
			<view class="list-cell b-b" :class="{ 'm-t': item.class === 'mT' }" v-for="item in setList"
				:key="item.title" @tap="navTo(item.url)" hover-class="cell-hover" :hover-stay-time="50">
				<text class="cell-tit">{{ item.title }}</text>
				<text class="cell-tip">{{ item.content }}</text>
				<text class="cell-more iconfont iconyou"></text>
			</view>
			<view class="list-cell log-out-btn" style="color: #1cbbb4;" @tap="toLogout">
				<text class="cell-tit">退出登录</text>
			</view>
			<!-- modal -->
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				loadProgress: 0,
				CustomBar: this.CustomBar,
				user: {},
				setList: this.$mConstDataConfig.setList,
				styleUserIsOpen: this.$mSettingConfig.styleUserIsOpen,
				notifyChecked: false,
				isNewVersion: false,
				colorModal: false,

			}
		},
		onShow() {
			uni.setNavigationBarColor({
				frontColor: '#ffffff',
				backgroundColor: '#1cbbb4',
				animation: {
					duration: 400,
					timingFunc: 'easeIn'
				}
			})
		},
		onLoad() {

		},
		methods: {
			handleTip(isNewVersion) {
				this.isNewVersion = isNewVersion;
			},
			handleVersionUpgradeShow() {
				this.isVersionUpgradeShow = false;
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
		}
	}
</script>

<style lang="scss">
	page {
		background: $page-color-base;
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
</style>