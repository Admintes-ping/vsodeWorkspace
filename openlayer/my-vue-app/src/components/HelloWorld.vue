<template>
  <div>
    <!-- 底图选择下拉框 -->
    <select v-model="selectedBaseMap" @change="onBaseMapChange" class="base-map-selector">
      <option value="tdt">天地图</option>
      <option value="osm">OpenStreetMap</option>
    </select>
    <!-- 地图容器 -->
    <div id="map" class="map"></div>
    <div  class="top" v-show="showTooltip">{{tooltipContent}}</div>
  </div>
</template>

<script>
import { ref, onMounted } from 'vue';
import Map from 'ol/Map';
import View from 'ol/View';
import TileLayer from 'ol/layer/Tile';
import XYZ from 'ol/source/XYZ';
import OSM from 'ol/source/OSM';
import GeoJSON from 'ol/format/GeoJSON';
import { fromLonLat } from 'ol/proj';
import { Style, Fill, Stroke } from 'ol/style';
import VectorSource from 'ol/source/Vector';
import VectorLayer from 'ol/layer/Vector';
import { ElTooltip } from 'element-plus';

export default {
  name: "Map",
  setup() {
    const map = ref(null);
    const selectedBaseMap = ref('tdt');
    const vectorSource = ref(new VectorSource());
    const vectorLayer = ref(null);

    // 记录当前高亮的feature，方便清除样式
    let highlightedFeature = null;


    // tooltip内容和显示状态
    const tooltipContent = ref('');
    const showTooltip = ref(false);
    const tooltipPosition = ref({ x: 0, y: 0 });

    const layers = {
      tdt: new TileLayer({
        source: new XYZ({
          url: 'http://t0.tianditu.gov.cn/vec_c/wmts?SERVICE=WMTS&REQUEST=GetTile&VERSION=1.0.0&LAYER=vec&STYLE=default&TILEMATRIXSET=c&FORMAT=tiles&TILEMATRIX={z}&TILEROW={y}&TILECOL={x}&tk=0cb005d118c303f597038536e23fa37a',
          maxZoom: 18,
          crossOrigin: 'anonymous'
        })
      }),
      osm: new TileLayer({
        source: new OSM(),
        zIndex: 0,
      })
    };

    onMounted(() => {
      vectorSource.value = new VectorSource();
      vectorLayer.value = new VectorLayer({
        source: vectorSource.value,
        style: defaultStyle
      });

      map.value = new Map({
        target: 'map',
        layers: [layers[selectedBaseMap.value], vectorLayer.value],
        view: new View({
          center: fromLonLat([116.397428, 39.90923]),
          zoom: 5,
          projection: 'EPSG:3857'
        })
      });

      // 点击事件监听
      map.value.on('click', evt => {
        // 获取点击位置的特征
        const feature = map.value.forEachFeatureAtPixel(evt.pixel, f => f);

        if (feature) {
          // 清除之前的高亮样式
          if (highlightedFeature && highlightedFeature !== feature) {
            highlightedFeature.setStyle(defaultStyle);
          }

          // 设置当前点击的特征为高亮
          feature.setStyle(highlightStyle);
          highlightedFeature = feature;

          // 获取并显示点击的省份名称
          const provinceName = feature.get('name');
          console.log('点击省份:', provinceName);

          // 显示 tooltip
          tooltipContent.value = `点击的省份是: ${provinceName}`;
          showTooltip.value = true;

          // 获取省份的几何中心并显示tooltip
          const geometry = feature.getGeometry();
          if (geometry.getType() === 'Polygon') {
            const center = geometry.getInteriorPoint().getCoordinates();
            const [x, y] = fromLonLat(center);
            tooltipPosition.value = { x, y };
          }
        }
      });

      loadGeoJSON('100000'); // 加载全国边界
    });

    // 底图切换
    const onBaseMapChange = () => {
      map.value.getLayers().setAt(0, layers[selectedBaseMap.value]);
    };

    // 加载GeoJSON数据
    const loadGeoJSON = async (code) => {
      try {
        const response = await fetch(`https://geo.datav.aliyun.com/areas_v3/bound/${code}_full.json`);
        if (!response.ok) {
          throw new Error('网络请求失败');
        }
        const geojsonData = await response.json();

        vectorSource.value.clear();

        const features = new GeoJSON().readFeatures(geojsonData, {
          featureProjection: 'EPSG:3857'
        });

        // 给所有feature设置默认样式
        features.forEach(f => f.setStyle(defaultStyle));

        vectorSource.value.addFeatures(features);

        const extent = vectorSource.value.getExtent();
        map.value.getView().fit(extent, { padding: [50, 50, 50, 50], maxZoom: 7 });
      } catch (error) {
        console.error('加载GeoJSON失败:', error);
      }
    };

    // 默认样式
    const defaultStyle = new Style({
      fill: new Fill({
        color: 'rgba(0, 0, 255, 0.1)'
      }),
      stroke: new Stroke({
        color: '#319FD3',
        width: 1
      })
    });

    // 高亮样式
    const highlightStyle = new Style({
      fill: new Fill({
        color: 'rgba(255, 0, 0, 0.5)'
      }),
      stroke: new Stroke({
        color: '#FF0000',
        width: 2
      })
    });

    return {
      map,
      selectedBaseMap,
      tooltipContent,
      showTooltip,
      tooltipPosition,
      onBaseMapChange
    };
  },
};
</script>

<style scoped>
.map {
  width: 100%;
  height: 100vh;
  position: absolute;
  top: 0;
  left: 0;
}

.base-map-selector {
  position: absolute;
  z-index: 1000;
  padding: 13px 20px;
  background: rgba(255, 255, 255, 0.9);
  border: 1px solid #ccc;
  border-radius: 4px;
  font-size: 20px;
  top: 10px;
  right: 30px;
}

.top{
  background: rgba(192, 192, 192, 0.9);
  border: 1px solid #ccc;
  border-radius: 4px;
  font-size: 20px;
  /* 居中关键代码 */
  top: 50%;          /* 从顶部 50% 开始 */
  left: 50%;         /* 从左侧 50% 开始 */
  transform: translate(-50%, -30%); /* 反向偏移自身宽高的50% */
  position: fixed; /* 改为 fixed 确保相对于视口定位 */
  z-index: 1000;
  padding: 10px 30px;
}
</style>
