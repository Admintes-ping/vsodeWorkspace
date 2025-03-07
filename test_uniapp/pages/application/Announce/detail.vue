<template>
	<view class="edit-weibo">
		<view class="header">
			<text class="title">编辑公告</text>
			<button @click="submitWeibo" :class="{ 'clicked': isButtonClicked }" class="subim">发布</button>
		</view>
		<textarea v-model="content" placeholder="说点什么..." class="textarea" @tap="Textarea" maxlength="-1"></textarea>
		<view class="image-preview">
			<image v-for="(img, index) in images" :key="index" :src="img" class="preview-image" />
			<button @click="chooseImage">上传图片</button>
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				content: '', // 微博内容
				images: [], // 上传的图片
				isButtonClicked: false // 控制按钮状态
			};
		},
		watch: {
			content(newValue) {
				// 根据 content 的长度改变按钮状态
				this.isButtonClicked = newValue.length > 0;
			}
		},
		methods: {
			chooseImage() {
				uni.chooseImage({
					count: 6 - this.images.length, // 限制最多选择9张图片（假设）
					success: (res) => {
						this.images = this.images.concat(res.tempFilePaths);
					}
				});
			},
			Textarea() {
				if (this.content.length > 0) {
					// 在点击后修改按钮状态
					this.isButtonClicked = true;
				} else {
					this.isButtonClicked = false;
				}
			},
			submitWeibo() {
				// 处理发布逻辑
				this.content = ''; // 发布后清空输入框
				console.log('微博内容:', this.content);
				console.log('上传的图片:', this.images);

				// 提交到服务器的逻辑（需实现）
			}
		}
	}
</script>

<style scoped>
	.edit-weibo {
		padding: 20px;
	}

	.title {
		font-size: 15px;
		font-weight: bold;

	}

	.textarea {
		width: 100%;
		padding: 10px;
		height: 780upx;
	}

	.header {
		display: flex;
		align-items: center;
		/* 垂直居中对齐 */
		margin-bottom: 10px;
		/* 增加与文本区域的间距 */
		z-index: 9999;
	}

	.image-preview {
		position: fixed;
		/* 固定在底部 */
		bottom: 10upx;
		/* 距离底部0 */
		left: 0;
		/* 距离左侧0 */
		right: 0;
		/* 距离右侧0 */
		display: flex;
		flex-wrap: wrap;
		margin-top: 10px;
	}

	.preview-image {
		width: 80px;
		height: 80px;
		margin-right: 10px;
	}

	.subim {
		z-index: 9999;
		border-radius: 20px;
		/* 设置圆角半径，可根据需要调整数值 */
		border: none;
		/* 去掉按钮边框 */
		background-color: #e5e5e5;
		/* 设置按钮背景颜色 */
		color: white;
		/* 设置字体颜色 */
		margin-left: 50%;
		height: 75upx;
	}

	.clicked {
		background-color: #1cbbb4;
		/* 点击后的颜色 */
		color: white;
		/* 点击后字体颜色变化 */
	}
</style>