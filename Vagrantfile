# -*- mode: ruby -*-
# vi: set ft=ruby :

################################################################################
#     Copyright (c) 2021 Arsene Temfack                                        #
#                                                                              #
#     SPDX-License-Identifier: MIT                                             #
################################################################################

Vagrant.configure("2") do |config|
  # For a complete reference, the online documentation is at
  # https://docs.vagrantup.com.
  # Every Vagrant development environment requires a box. They can be search at
  # https://vagrantcloud.com/search.
  
  # CentOS Virtual Machine
  config.vm.define "CentosCube-vm" do |vm1|
    vm1.vm.hostname = "CentOsCube-vm"
    vm1.vm.box = "bento/centos-7.2"
    vm1.vm.network "private_network", ip: "192.168.33.16"
    vm1.vm.synced_folder ".", "/vagrant_data",type:"virtualbox"

    vm1.vm.provider "virtualbox" do |vb|
      vb.name = "CentOsCube"
      vb.gui = true
      vb.cpus = "1"
      vb.memory = "1024"
    end

    vm1.vm.provision "shell", inline: <<-SHELL
      yum update
	  yum groupinstall -y 'gnome desktop'
	  yum install -y 'xorg*'
	  yum remove -y initial-setup initial-setup-gui
	  systemctl isolate graphical.target
      systemctl set-default graphical.target
    SHELL
  end
end
