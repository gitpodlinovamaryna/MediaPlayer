#!/bin/bash

echo -e "Removing 'src-gen' folder...\n"
rm -rf src-gen

./cgen/commonapi-generator/commonapi-generator-linux-x86_64 -sk fidl/MediaPlayer.fidl
./cgen/commonapi_dbus_generator/commonapi-dbus-generator-linux-x86_64 fidl/MediaPlayer.fidl
