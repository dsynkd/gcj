<>;
print("CASE #" . (++$c) . ": " . join(" ",reverse(split(" ", $line))) . "\n") while($line = <>);
