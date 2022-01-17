# K8sScript
## k8s在容器中启动脚本

根据最新的k8s的参数写的启动脚本,一共启动了七个容器,分别运行k8s的各个部分

bug:在kubectl中查询不到节点的存在，查看日志发现kubelet启动时无法挂载主目录，显示操作不允许

NEXT:连接安全性不可保证，添加证书等

## K8s 在多主机上启动
### 启动脚本
### 启动service&config配置

参考网址[Ubuntu上手动安装Kubernetes](https://blog.csdn.net/styshoo/article/details/69220086)
