# Kernel Compilation

### Installation

```bash  
sudo apt-get install build-essential rsync gcc bc bison libssl-dev libncurses5-dev libelf-dev dwarves
```

### Increase the bootloader timeout

```bash
sudo nano /etc/default/grub
#GRUB_TIMEOUT_STYLE=hidden
GRUB_TIMEOUT=10
sudo update-grub	
```

### Download kernel source code from kernel.org

```bash
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.6.9.tar.gz
```

### Extract the skernel source code

```bash
mkdir LinuxKernel
tar xvf linux-* -C LinuxKernel/ --strip-components=1
```

### Check the extracted source code

```bash
cd LinuxKernel
ls
du -sh
```

### Configure the kernel compilation

```bash
cp /boot/config-$(uname -r) ./.config 
```

The above command will copy the config file that came up with the distribution. Another method is by generating the config file based on the currently connected h/w and for that we can execute the make command.

```bash
make localmodconfig
``` 

### Compile the kernel

We will use the first method for compiling the kernel with the config file that came up with the distribution.
  
```bash
make deb-pkg 
```
If you get any error such as 

```bash
make[1]: *** No rule to make target 'debian/canonical-certs.pem', needed by 'certs/x509_certificate_list'.  Stop.
make: *** [Makefile:1809: certs] Error 2
```

You need to do the following....<br>
In your kernel configuration file you will find this line:
```bash
CONFIG_SYSTEM_TRUSTED_KEYS="debian/canonical-certs.pem"
```
Change it to this:
```bash
CONFIG_SYSTEM_TRUSTED_KEYS=""
```
Wait for the compilation time as it takes a long time.

### Install the kernel packages

To install the newly compiled kernel package use the following command

```bash
cd 
sudo dpkg -i linux-*.deb
```

