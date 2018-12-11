package main 

import (
	"Byzgo/replica"
)

func main() {
	replica.ByzInitReplica("../bft/config")
	replica.ByzRunReplica()
}
