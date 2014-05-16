<?php

$json = false;

if (isset($_GET["json"])) {
	$json = true;
}

$filename = "status";
if ($content = file_get_contents($filename)) {

	if (substr($content,0,1) == "1") {
		if ($json) {
			echo "{\"status\":1, \"timestamp\": " . substr($content,2, strlen($content) -2) . "}";
		} else {
			echo "open";
		}
	} else {
		if ($json) {
			echo "{\"status\":0, \"timestamp\": " . substr($content,2, strlen($content) -2) . "}";
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
