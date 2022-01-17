# reload daemon
sudo systemctl daemon-reload

# Run flanneld
# config:/etc/default/flanneld.conf
# service:/lib/systemd/system/flanneld.service
# only node need this!!!
systemctl start flanneld

sleep 5

# Restart docker
# config&service:/lib/systemd/system/docker.service.d/flannel.conf
sudo systemctl restart docker

# Run kublet
# data dir:/var/lib/kubelet
# config:/etc/kubernetes/kubelet
# service:/lib/systemd/system/kubelet.service
sudo systemctl start kubelet

# Run kube-proxy
# config:/etc/kubernetes/proxy
# service:/lib/systemd/system/kube-proxy.service
sudo systemctl start kube-proxy

