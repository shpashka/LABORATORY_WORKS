t=".jpg"
k=2
for f in *"$t";
do
z=$(stat -c '%y' "$f")
c=${z:0:16};
if [ -f "$c$t" ];
then
mv "$f" "$c^$k^$t"
k=$(($k+1));
else
mv "$f" "$c$t"
fi;
done
