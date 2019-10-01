User-friendly xlsx library for C++14, [tfussell/xlnt](https://github.com/tfussell/xlnt)

```
pacman -Ss\
	mingw-w64-i686-xlnt 
	mingw-w64-x86_64-xlnt
```

```
termux-chroot
git clone https://github.com/tfussell/xlnt.git
mkdir ./tfussell/build
cd ./tfussel/build
cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr ../
make -j8
make install
```
