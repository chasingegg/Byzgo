package main

import (
	"Byzgo/replica"
)

func main() {
	replica.ByzInitReplica("./bft/config", "./bft/config_private/template")
}
