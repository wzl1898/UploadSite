from django import forms
from django.contrib import auth
from django.contrib.auth.models import User

class LoginForm(forms.Form):
    username = forms.CharField(label='用户名', widget=forms.TextInput(attrs={'class':'form-control'}))
    password = forms.CharField(label='密码', widget=forms.PasswordInput(attrs={'class':'form-control'}))
    def clean(self):
        username = self.cleaned_data['username']
        password = self.cleaned_data['password']
        user = auth.authenticate(username = username, password = password)
        if user is None:
            raise forms.ValidationError('用户名或密码不正确')
        else:
            self.cleaned_data['user'] = user
        return self.cleaned_data

class RegForm(forms.Form):
    username = forms.CharField(label='用户名', widget=forms.TextInput(attrs={'class': 'form-control'}))
    email = forms.EmailField(label='邮箱', widget=forms.TextInput(attrs={'class': 'form-control'}))
    password_again = forms.CharField(label='确认密码', widget=forms.PasswordInput(attrs={'class': 'form-control'}))
    password = forms.CharField(label='密码', widget=forms.PasswordInput(attrs={'class': 'form-control'}))

    def __init__(self, *args, **kwargs):
        if 'request' in kwargs:
            self.request = kwargs.pop('request')
        super(RegForm, self).__init__(*args, **kwargs)

    def clean(self):
        pwd_again = self.cleaned_data['password_again']
        if pwd_again == '':
            raise forms.ValidationError('密码不能为空')
        else:
            return self.cleaned_data
    def clean_username(self):
        username = self.cleaned_data['username']
        if username == '':
            raise forms.ValidationError('用户名不能为空')
        if User.objects.filter(username=username).exists():
            raise forms.ValidationError('用户名已存在')
        else:
            return username
    def clean_password(self):
        pwd = self.cleaned_data['password']
        pwd_again = self.cleaned_data['password_again']
        if pwd == '':
            raise forms.ValidationError('密码不能为空')
        if not (pwd == pwd_again):
            raise forms.ValidationError('两次输入密码不一样')
        else:
            return pwd