#!/bin/bash

# Run ectd container
echo "Starting ectd container..."
sudo docker run -d --name="etcd" -p 4001:4001 gcr.io/google_containers/etcd:3.1.17 /usr/local/bin/etcd \
	--data-dir=/var/etcd/data \
	--listen-client-urls=http://0.0.0.0:4001 \
  	--advertise-client-urls=http://127.0.0.1:4001
				      
# Run apiserver container
echo "Starting apiserver container..."
sudo docker run -d -v /var/run/docker.sock:/var/run/docker.sock --net=host --pid=host --name="apiserver" -p 8080:8080 kubernetes:latest /hyperkube kube-apiserver \
	--service-cluster-ip-range=10.0.0.1/24 \
    --etcd-servers=http://127.0.0.1:4001 \
	--advertise-address=127.0.0.1 \
    --bind-address=127.0.0.1 \
	--insecure-bind-address=127.0.0.1 \
	--admission-control=NamespaceLifecycle,NamespaceExists,LimitRanger,SecurityContextDeny,ResourceQuota \
	--v=4 

sleep 10

# Run controller-manager container
echo "Starting controller-manager container..."
sudo docker run -d -v /var/run/docker.sock:/var/run/docker.sock --net=host --name="controller-manager" kubernetes:latest /hyperkube kube-controller-manager --master=127.0.0.1:8080 --v=4  
 

# Run scheduler container
echo "Starting scheduler container..."
sudo docker run -d -v /var/run/docker.sock:/var/run/docker.sock --net=host --name="scheduler" kubernetes:latest /hyperkube kube-scheduler --master=127.0.0.1:8080 --v=4
                                                                                                                  
# Run kubelet container
echo "Starting kubelet container..."
sudo docker run -v /home/geniusrabbit/single-kubernetes-docker:/mnt -v /:/rootfs:ro -v /sys:/sys:ro -v /var/run/docker.sock:/var/run/docker.sock -d --net=host --pid=host -v /var/run/docker.sock:/var/run/docker.sock --name="kubelet"  gcr.io/google_containers/hyperkube:v0.14.1 /hyperkube kubelet --v=2 --config=/etc/kube.conf  --hostname_override=127.0.0.1 --api_servers=http://127.0.0.1:8080

#rootdir=mnt                                                                                                   
# Run proxy container
echo "Starting proxy container..."

sudo docker run -d --net=host --privileged=true --name="proxy" kubernetes:latest /hyperkube proxy --master=http://127.0.0.1:8080 --hostname-override=127.0.0.1 --v=4


#Run kubectl container
#-v /home/geniusrabbit/single-kubernetes-docker:/mnt
echo "Starting kubectl container..."                                                                 
#sudo docker run -id --net=host -e "KUBERNETES_MASTER=http://localhost:4001" --name="kubectl" --hostname="kubectl" roffe/kubectl:latest bash 
sudo docker run -id --net=host -e "KUBERNETES_MASTER=http://127.0.0.1:8080" --name="kubectl" --hostname="kubectl" kubernetes:latest bash
#Get into the kubectl container
sudo docker exec -it kubectl bash
