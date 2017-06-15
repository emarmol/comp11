#!/bin/sh
#
# animals.sh -- the animals game using the directory structure as a db
#
# usage: animals.sh directory
# notes: each directory is a branch or a terminal node
#        a branch has a file called question and two subdirs called yes and no
#	 a terminal node has one file called animal
#
# hist: 2012-04-24 added mode setting for new nodes

	FMODE=664		# file mode
	DMODE=775		# dir  mode

	if test $# -eq 0 ; then
		echo usage: `basename $0` startingdir
		exit 1
	fi

        #
        # main program: change into root of database, then check type of node
        #               if leaf, guess animal, otherwise ask question
	main()
	{
		### change into starting directory or die
		START=$1
		cd $START || exit 1	# cmd1 || cmd2 == if cmd1 fails do cmd2

		# traverse tree until we get to a dir with no question
		while test -f question
		do
			if yesno "`cat question`"
			then
				cd yes
			else
				cd no
			fi
		done

		ANIMAL="`cat animal`"
		if yesno "Are you thinking of `a_or_an $ANIMAL`"
		then
			echo "I thought so."
		else
			newbranch
		fi
	}

	#
	# yesno - ask question, respond with 0 for yes, 1 for no
	#
	yesno()
	{
		while true ; do
			printf "%s? " "$1"
			read ans
			case "$ans" in
				y*|Y*)	return 0	;;
				n*|N*)	return 1	;;
			esac
		done
	}
	#
	# newbranch - 	create a new branch
	#	      	ask for new animal, a question, an answer for new
	newbranch()
	{
		CURR=`cat animal`
		# exit on no answer
		printf "What animal were you thinking of? "
		read NEW
		[ -z "$NEW" ] && exit 0	  # cmd1 && cmd2 == if cmd1 then do cmd2

		# get distinguishing question
		printf "What question distinguishes `a_or_an $NEW` "
		echo "from `a_or_an $CURR?`"
		printf ": "
		read QUEST
		QUEST="`echo "$QUEST" | sed 's/?//'`"	# remove "?"
		[ -z "$QUEST" ] && exit 0

		# get answser
		if yesno "Is the answer for `a_or_an $NEW` yes or no"
		then
			ans=yes ; oth=no
		else
			ans=no  ; oth=yes
		fi

		# make branch
		if make_branch "$NEW" "$QUEST" $ans $oth
		then
			echo "$NEW added to db"
			exit 0
		else
			echo "Cannot add $NEW to db"
			exit 1
		fi
	}
	#
	# args are animal, quest, {yes|no}, {no|yes}
	#
	make_branch()
	{
		mkdir yes no          || return 1	# make two subdirs
		chmod $DMODE yes no   || return 1
		echo "$2" > question  || return 1	# add node question
		chmod $FMODE question || return 1
		echo "$1" > $3/animal || return 1	# new animal into dir1
		chmod $FMODE $3/animal|| return 1	
		mv animal $4          || return 1	# old animal in other
		return 0				# ok!
	}

	# add "a" or "an" to argument
	a_or_an()
	{
		case "$1" in
			[aeiouAEIOU]*)	echo "an $*"	;;
			*)		echo "a $*"	;;
		esac
	}

	##########################################
	#           main called here             #
	##########################################

	main "$1"
