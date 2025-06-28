make clean
make ABC_USE_PIC=1 ABC_USE_NO_READLINE=1 libabc.so -j12
cd ABC-python || exit
swig -python ABC.i
gcc -fPIC -I /rshome/daikang.kuang/anaconda3/include/python3.12 -I ./src ABC_wrap.c -c -o ABC_wrap.o  # 添加输出文件选项 -o
g++ -shared -fPIC -o _ABC.so ABC_wrap.o /rshome/daikang.kuang/PowerAwareSynthesis/netlist/abc/libabc.so
pip install .