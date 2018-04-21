echo "Enter the extension to be moved : "
read ext
echo "Enter the folder to be made : "
read name
mkdir -p name
mv -i *.$ext name
