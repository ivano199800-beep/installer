
installed="{$HOME}/installed"
sudo apt install git -y
sudo apt install lua5
echo 'starting installation'
mkdir "$installed"
mkdir "{$installed}/installer"
cd "{$installed}/installer"
git clone https://github.com/ivano199800-beep/installer
