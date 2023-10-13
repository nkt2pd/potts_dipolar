#!/bin/bash


#SBATCH --job-name=potts_dipolar20

#SBATCH --ntasks=1

#SBATCH -A cherngroup

#SBATCH --mem=32G

#SBATCH -p standard

#SBATCH --cpus-per-task=10

#SBATCH --time=7-00:00:00

#SBATCH -o potts20sbatch.out

./potts_dipolar_Wolff.exe 20
