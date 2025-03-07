<template>
	<view class="helperList" v-if="!loading">
		<!-- 帮助列表 -->
		<view v-if="helperList.length > 0">
			<uni-collapse v-for="(fItem, fIndex) in helperList" :key="fIndex">
				<uni-collapse-item open :title="fItem.title">
					<view class="helper-child-item" v-for="(sItem, sIndex) in fItem.child" :key="sIndex"
						@tap="navTo(sItem.url)">
						<text>{{ sItem.title }}</text>
						<text class="iconfont iconyou"></text>
					</view>
				</uni-collapse-item>
			</uni-collapse>
		</view>
		<oa-empty info="暂无站点帮助" v-if="helperList.length === 0 && !loading"></oa-empty>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				loading: true,
				helperList: [{
					"id": "1",
					"title": "用户中心",
					"pid": "0",
					"level": "1",
					"child": [{
						"id": "2",
						"title": "怎样注册用户",
						"pid": "1",
						"level": "2",
						"url": "",
						"child": []
					}, {
						"id": "3",
						"title": "用户密码忘记了怎么办？",
						"pid": "1",
						"level": "2",
						"url": "",
						"child": []
					}, {
						"id": "4",
						"title": "能使用手机验证码登陆吗？",
						"pid": "1",
						"level": "2",
						"url": "",
						"child": []
					}, {
						"id": "5",
						"title": "可自动记住账号密码吗？",
						"pid": "1",
						"level": "2",
						"url": "",
						"child": []
					}]
				}, {
					"id": "6",
					"title": "审批流程",
					"pid": "0",
					"level": "1",
					"child": [{
						"id": "7",
						"title": "怎样报销？",
						"pid": "6",
						"level": "2",
						"url": "",
						"child": []
					}, {
						"id": "8",
						"title": "报修流程",
						"pid": "6",
						"level": "2",
						"url": "",
						"child": []
					}, {
						"id": "9",
						"title": "怎样领用物品",
						"pid": "6",
						"level": "2",
						"url": "",
						"child": []
					}, {
						"id": "10",
						"title": "怎样请假？",
						"pid": "6",
						"level": "2",
						"url": "",
						"child": []
					}]
				}, {
					"id": "11",
					"title": "考勤管理",
					"pid": "0",
					"level": "1",
					"child": [{
						"id": "12",
						"title": "排班",
						"pid": "11",
						"level": "2",
						"url": "",
						"child": []
					}, {
						"id": "13",
						"title": "班次设置",
						"pid": "11",
						"level": "2",
						"url": "",
						"child": []
					}, {
						"id": "14",
						"title": "怎样查看自己的排班",
						"pid": "11",
						"level": "2",
						"url": "",
						"child": []
					}, {
						"id": "15",
						"title": "怎样签到和签退",
						"pid": "11",
						"level": "2",
						"url": "",
						"child": []
					}]
				}],
				page: 1
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
			this.loading = false;
		},
		methods: {
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
		}
	}
</script>

<style lang="scss" scoped>
	page {
		background-color: $page-color-base;
	}

	.helperList {
		margin-top: $spacing-base;

		.helper-child-item {
			margin: $spacing-base $spacing-lg;
			display: flex;
			justify-content: space-between;
		}
	}
</style>