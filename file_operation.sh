#!/bin/bash

while true
do
    echo "------ MENU ------"
    echo "1. Create File"
    echo "2. Delete File"
    echo "3. Copy File"
    echo "4. List Files"
    echo "5. Exit"

    echo -n "Enter choice: "
    read ch

    case $ch in

    1)
        echo -n "Enter filename: "
        read file
        touch $file
        echo "File Created"
        ;;

    2)
        echo -n "Enter filename: "
        read file
        rm $file
        echo "File Deleted"
        ;;

    3)
        echo -n "Enter source file: "
        read s

        echo -n "Enter destination file: "
        read d

        cp $s $d
        echo "File Copied"
        ;;

    4)
        ls
        ;;

    5)
        echo "Exit"
        break
        ;;

    *)
        echo "Invalid Choice"
        ;;
    esac

    echo
done