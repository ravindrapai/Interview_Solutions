class Single:
  class __Single:
    def __init__(self, arg):
      self.val = arg
    def __str__(self):
      return `self` + self.val
  instance = None
  def __init__(self, arg):
    if not Single.instance:
      Single.instance = Single.__Single(arg)
    else:
      Single.instance.val = arg
  def __getattr__(self, name):
    return getattr(self.instance, name)

