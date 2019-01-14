$count = <>;
while($a++<$count) {
	$done = true;
	$c = <> + 0;
	$l = <>;
	$ps = <>;
	@p = split(' ', $ps);
	for($x = 0; $x < $l && $done == true; $x++) {
		for($y = ($x+1); $y < $l; $y++) {
			if(@p[$x] + @p[$y] == $c) {
				$done = false;
				print("Case #$a: " . ($x+1) . " " . ($y+1) . "\n");
			}
		}		
	}
}
