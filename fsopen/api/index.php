<?php

$json = false;

if (isset($_GET["json"])) {
	$json = true;
}

$filename = "/var/www/openfs/status";
if ($content = file_get_contents($filename)) {

	if (substr($content,0,1) == "1") {
		if ($json) {
			echo "{\"status\":1}";
		} else {
			echo "open";
		}
	} else {
		if ($json) {
			echo "{\"status\":0}";
		} else {
			echo "closed";
		}
	}
	
} else {
	if ($json) {
		echo "{\"status\":\"Error: File not found!!!\"}";
	} else {
		echo "Error: file not found!!!";
	}
}

?>
