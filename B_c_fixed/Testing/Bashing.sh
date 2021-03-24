#!bin/bash
NEVENT=1000000
for i in {1..100}; do
    let seed=435624535*$i
    echo "#!/bin/bash" >> 100run$i.sh
    echo cd `pwd` >> 100run$i.sh
    echo "Herwig run LHC100.run -N "$NEVENT --seed $seed >> 100run$i.sh
done
