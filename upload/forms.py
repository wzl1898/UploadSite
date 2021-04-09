from django import forms
from django.contrib import auth

class Upload_form(forms.Form):
    file = forms.FileField(required=True, label='选择文件',)
    def __init__(self, *args, **kwargs):
        if 'user' in kwargs:
            self.user = kwargs.pop('user')
        super(Upload_form, self).__init__(*args, **kwargs)

    def clean(self):

        if self.user.is_authenticated:
            self.cleaned_data['user'] = self.user
        else:
            raise forms.ValidationError('用户未登录')

        file = self.cleaned_data['file']
        if file is None:
            raise forms.ValidationError('文件不能为空')
        return self.cleaned_data

