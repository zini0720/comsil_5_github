echo "working directory: "
read dir

if [ $dir ]	# 디렉토리 존재 확인
then

	cd $dir #디렉토리 이동

	if [ $? -ne 0 ] # 이동(접근)  불가능할 때

	then
		echo "Error : directory access unavailable"
		exit 0
	fi

fi



for i in * #모든 파일 access
do
	if [ -f $i ]
	then
		mv $i `echo $i | tr '[A-Z][a-z]' '[a-z][A-Z]'`
	fi

done
