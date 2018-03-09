make clean &&
make --trace &> making.log &&
cat making.log \
| grep -v -E "(update target|warning:|^ |^echo|^Makefile|^mkdir)"  \
| grep -E "(^\+ |^\+ ld|^ld|^gcc|^objdump|^dd|^objcopy|^#)"

#| grep -E "(^ld)"   
#| grep -E "(^gcc)"   
rm  making.log

