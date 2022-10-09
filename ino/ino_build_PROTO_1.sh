BASEDIR=$(readlink -f $(dirname "$0"))
cd ../PROTO_1
ino build && ino upload -p /dev/ttyS0 #COM1 in VirtualBox means ttyS0
