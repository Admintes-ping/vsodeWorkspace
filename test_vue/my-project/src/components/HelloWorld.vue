<template>
  <div>
    <!-- 设置画布大小 -->
    <canvas ref="chart" width="600" height="500"></canvas>
  </div>
</template>

<script>
import { Chart, registerables } from 'chart.js';
Chart.register(...registerables);

export default {
  name: 'HelloWorld',
  data() {
    return {};
  },
  mounted() {
    this.renderChart();
  },
  methods: {
    renderChart() {
      const ctx = this.$refs.chart.getContext('2d');
      const data = {
        labels: [], // x 轴标签
        datasets: [
          {
            label: 'cos(x)', // 数据集标签
            data: [], // cos(x) 数据
            borderColor: 'blue', // 线条颜色
            fill: false, // 不填充
          },
          {
            label: 'sin(x)', // 数据集标签
            data: [], // sin(x) 数据
            borderColor: 'red', // 线条颜色
            fill: false, // 不填充
          },
        ],
      };

      // 生成数据
      for (let x = -2 * Math.PI; x <= 2 * Math.PI; x += 0.1) {
        data.labels.push(x.toFixed(2)); // x 轴标签
        data.datasets[0].data.push({ x: x, y: Math.cos(x) }); // cos(x) 数据
        data.datasets[1].data.push({ x: x, y: Math.sin(x) }); // sin(x) 数据
      }

      // 绘制图表
      new Chart(ctx, {
        type: 'line', // 折线图
        data: data,
        options: {
          responsive: false, // 禁用响应式布局
          maintainAspectRatio: false, // 不保持宽高比
          scales: {
            x: {
              type: 'linear', // x 轴类型
              position: 'bottom', // x 轴位置
              min: -2 * Math.PI, // x 轴最小值
              max: 2 * Math.PI, // x 轴最大值
              grid: {
                color: 'rgba(0, 0, 0, 0.1)', // 网格线颜色
              },
              ticks: {
                stepSize: Math.PI / 2, // x 轴刻度间隔
                callback: function (value) {
                  // 将刻度值转换为 π 的倍数
                  if (value === 0) return '0';
                  return (value / Math.PI).toFixed(2) + 'π';
                },
              },
            },
            y: {
              type: 'linear', // y 轴类型
              min: -1.5, // y 轴最小值
              max: 1.5, // y 轴最大值
              grid: {
                color: 'rgba(0, 0, 0, 0.1)', // 网格线颜色
              },
              ticks: {
                stepSize: 0.5, // y 轴刻度间隔
              },
            },
          },
          plugins: {
            // 添加 x 轴和 y 轴线
            annotation: {
              annotations: {
                xAxis: {
                  type: 'line',
                  scaleID: 'x',
                  value: 0, // x 轴位置
                  borderColor: 'black', // 轴线颜色
                  borderWidth: 2, // 轴线宽度
                },
                yAxis: {
                  type: 'line',
                  scaleID: 'y',
                  value: 0, // y 轴位置
                  borderColor: 'black', // 轴线颜色
                  borderWidth: 2, // 轴线宽度
                },
              },
            },
          },
        },
      });
    },
  },
};
</script>

<style scoped>
/* 设置画布容器的样式 */
css
复制
canvas {
  width: 400px; /* 画布宽度 */
  height: 300px; /* 画布高度 */
  border: 1px solid #ccc; /* 可选：添加边框 */
}
</style>