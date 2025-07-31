deactivate
rm -rf ./venv || 1
make distclean && ./configure && make -j8
./python -m venv venv
#./venv/bin/python -m pip install textual-dev
./venv/bin/python -m pip install -e ../textual ../textual-dev
source ./venv/bin/activate
textual console