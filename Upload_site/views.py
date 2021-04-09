import random
import string
import time
from django.shortcuts import render, redirect
from user.forms import LoginForm, RegForm
from django.contrib import auth
from django.contrib.auth.models import User
from upload.models import upload_record
from upload.forms import Upload_form
from django.core.mail import send_mail
from django.http import JsonResponse
import os
def index(request):
    form = Upload_form()
    context = {}
    context['form'] = form
    return render(request, 'index.html', context)

def upload_files(request):
    if not request.user.is_authenticated:
        return redirect('/login')
    else:
        form = Upload_form(request.POST, request.FILES, user=request.user)
        if form.is_valid():
            file = form.cleaned_data['file']
            now_dir = os.getcwd()
            if os.path.exists(now_dir + '/uploaded_files/' + f'{request.user.username}'):
                print(now_dir)
                with open('uploaded_files/' + f'{request.user.username}/' + f'{file.name}', 'wb') as f:
                    f.write(file.read())
            else:
                os.makedirs(now_dir + '/uploaded_files' + f'/{request.user.username}')
                with open('uploaded_files/' + f'{request.user.username}/' + f'{file.name}', 'wb') as f:
                    f.write(file.read())
            new_record = upload_record()
            new_record.user = request.user
            new_record.file_name = file.name
            print(file.name)
            new_record.save()
            return redirect('/')
        else:
            return redirect('error')


def login(request):
    if request.method == 'POST':
        login_form = LoginForm(request.POST)
        if login_form.is_valid():
            user = login_form.cleaned_data['user']
            auth.login(request, user)
            return redirect('/')
    else:
        login_form = LoginForm()
    context = {}
    context['login_form'] = login_form
    return render(request, 'login.html', context)

def logout(request):
    auth.logout(request)
    return redirect('/')

def register(request):
    if request.method == 'POST':
        reg_form = RegForm(request.POST, request=request)
        if reg_form.is_valid():
            username = reg_form.cleaned_data['username']
            email = reg_form.cleaned_data['email']
            password = reg_form.cleaned_data['password']
            user = User.objects.create_user(username, email, password)
            user.save()
            auth.login(request, user)
            return redirect('/')
    else:
        reg_form = RegForm()
    context = {}
    context['reg_form'] = reg_form
    return render(request, 'register.html', context)


def home(request):
    if not request.user.is_authenticated:
        return redirect('/')
    else:
        user = request.user
        file_recs = upload_record.objects.filter(user=user)
        print(file_recs)
        context = {}
        context['username'] = user.username
        context['email'] = user.email
        context['file_recs'] = file_recs
        return render(request, 'home.html', context)




















