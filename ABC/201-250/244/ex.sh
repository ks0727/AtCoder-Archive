set t=1
while true;do
  python a.py > pyt.txt
  ./c < pyt.txt
  ./c > cp.txt
  python a.py < cp.txt
  $t = $t+1
  if $t > 10000;then
    break
  fi
done
