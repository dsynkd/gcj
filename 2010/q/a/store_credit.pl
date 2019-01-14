$N = <>;
while($n++<$N) {
	$C = <> + 0;
	$I = <> + 0;
	@P = split(' ',<>);
	$done = false;
	for($x = 0; $x < $I && $done == false; $x++) {
		for($y = ($x+1); $y < $I; $y++) {
			if(@P[$x] + @P[$y] == $C) {
				$done = true;
				print("Case #$n: " . ($x+1) . " " . ($y+1) . "\n");
				break;
			}
		}		
	}
}
