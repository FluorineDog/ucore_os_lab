make clean &&
make --trace &> making.log &&
cat making.log | grep -v -E "(update target|warning:|^ |^echo|^Makefile|^mkdir)" | grep -v -E "(^gcc|^ld)"  | grep  -E "(^\+ |^\+ ld|^gcc|^ld|^objdump|^dd|^objcopy|^#)"
