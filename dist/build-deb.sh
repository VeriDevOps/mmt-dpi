# Where the sdk/ compiled source code
sdk_dir=../sdk

# Set name of package with given version
build_dir=mmt_sdk

# Create a directory with the name of package
mkdir $build_dir

# Create control
mkdir $build_dir/DEBIAN/
cp DEBIAN/* $build_dir/DEBIAN/

mkdir $build_dir/usr/
mkdir $build_dir/usr/local/
mkdir $build_dir/usr/local/include/
mkdir $build_dir/usr/local/include/mmt/
cp $sdk_dir/include/*.* $build_dir/usr/local/include/mmt/
echo "#include \"mmt/mmt_core.h\"">>$build_dir/usr/local/include/mmt_core.h
cp -R $sdk_dir/lib $build_dir/usr/

mkdir $build_dir/opt/
mkdir $build_dir/opt/mmt/
mkdir $build_dir/opt/mmt/plugins
cp $sdk_dir/lib/libmmt_tcpip.so $build_dir/opt/mmt/plugins
cp -R $sdk_dir/examples/ $build_dir/opt/mmt

dpkg-deb --build $build_dir

rm -rf $build_dir