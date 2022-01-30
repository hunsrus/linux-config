#!/bin/bash
./calc $(cat /sys/class/power_supply/BAT0/energy_now) $(cat /sys/class/power_supply/BAT0/energy_full)
