#!bin/bash
NEVENT=1000000
for i in {1..100}; do
    let seed=435624535*$i
    echo "#!/bin/bash" >> run$i.sh
    echo cd `pwd` >> run$i.sh
    echo "Herwig run LHC.run -N "$NEVENT --seed $seed >> run$i.sh
done