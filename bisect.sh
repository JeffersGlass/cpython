rm -rf ./venv
rm -rf ./result.txt
re -rf ./compare.txt
make distclean || 1
./configure
make -j8 || exit 125
./python -m venv venv
./venv/bin/python -m pip install pyperformance
./venv/bin/python -m pyperf system tune || exit 125
./venv/bin/python -m pyperformance run --rigorous --benchmarks nbody --output result.txt
./venv/bin/python -m pyperformance compare ./original.txt ./result.txt > compare.txt
DIFFERENCE="$(./venv/bin/python ./getmean.py compare.txt)"
echo 'Found that regression was' $DIFFERENCE
if (( echo $DIFFERENCE'>0.90' | bc -l)); then
    return 1
else
    return 0
fi

