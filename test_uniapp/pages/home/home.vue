<template>
	<view>
		<view style="margin-top: 40rpx;">
			<view class="list-cell b-b" v-for="item in setList" :key="item.title"
				 :hover-stay-time="50">
				<text class="cell-tit">{{ item.title }}</text>
				<text class="cell-more iconfont iconyou"></text>
			</view>
		</view>
		<view>
			<view class="list-cell b-b" v-for="item in setList" :key="item.title"
				 >
				<text class="cell-tit">{{ item.title }}</text>
				<text class="cell-more iconfont iconyou"></text>
			</view>
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				setList: [{
					title: "查看食品安全档案"
				}, {
					title: "查看商家青山档案"
				}, {
					title: "到店吃"
				}, {
					title: "到店吃"
				}]
			};
		},
		methods: {

		},
	};
</script>

<style>
	/* 你可以在这里添加样式 */
</style>