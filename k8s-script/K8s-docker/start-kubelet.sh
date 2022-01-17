#! /bin/bash

# Run ectd container
echo "Starting ectd container..."
sudo docker run -d --name="etcd" -p 4001:4001 gcr.io/google_containers/etcd:3.1.17 /usr/local/bin/etcd \
    --data-dir=/var/etcd/data \
    --listen-client-urls=http://0.0.0.0:4001 \
    --advertise-client-urls=http://127.0.0.1:4001


# Run kubelet container
echo "Starting kubelet container..."
sudo docker run  -d --net=host --pid=host  --name="kubelet"  gcr.io/google_containers/hyperkube:v0.14.1 /hyperkube kubelet \
    -v /home/geniusrabbit/single-kubernetes-docker:/mnt \
    -v /var/run/docker.sock:/var/run/docker.sock \
    #-v /:/rootfs:ro \
    -v /sys:/sys:ro \
    --hostname_override=127.0.0.1 \
    --api_servers=http://127.0.0.1:8080 \
    --config=/etc/kube.conf \
    --v=2  