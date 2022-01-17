#!/bin/bash

# Run etcd
# config:/etc/etcd/etcd.conf
# service:/lib/systemd/system/etcd.service
systemctl start etcd

# Run flanneld
# config:/etc/default/flanneld.conf
# service:/lib/systemd/system/flanneld.service
# only node need this!!!
#systemctl start flanneld

sleep 5


# k8s
# config /etc/kubernetes
# all can use :/etc/kubernetes/config

# kube-apiserver kube-controller-manager kube-scheduler

# Run kube-apiserver
# config:/etc/kubernetes/apiserver
# service:/lib/systemd/system/kube-apiserver.service
systemctl start kube-apiserver

# Run controller-manager
# config:/etc/kubernetes/controller-manager
# service:/lib/systemd/system/kube-controller-manager.service
systemctl start kube-controller-manager

# Run kube-scheduler
# config:/etc/kubernetes/scheduler
# service:/lib/systemd/system/kube-scheduler.service
systemctl start kube-scheduler



